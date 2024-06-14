% Open the existing figure
fig = openfig('existing_figure.fig', 'invisible');

% Get the axes handles
ax = findall(fig, 'Type', 'axes');

% Initialize a cell array to hold the generated code
generated_code = {};

% Generate code to create a new figure
generated_code{end+1} = 'figure;';

% Loop through each axes and extract properties
for i = 1:length(ax)
    ax_props = get(ax(i));
    
    % Generate code to create new axes with the same position
    generated_code{end+1} = sprintf('axes(''Position'', [%f %f %f %f]);', ...
        ax_props.Position);
    
    % Set axes properties (excluding Position, since it's set during creation)
    ax_fields = fieldnames(ax_props);
    for f = 1:length(ax_fields)
        field_name = ax_fields{f};
        if strcmp(field_name, 'Position')
            continue;
        end
        field_value = ax_props.(field_name);
        if isnumeric(field_value)
            value_str = mat2str(field_value);
        else
            value_str = ['''' field_value ''''];
        end
        generated_code{end+1} = sprintf('set(gca, ''%s'', %s);', field_name, value_str);
    end
    
    % Get the children of the axes (e.g., lines, patches)
    children = get(ax(i), 'Children');
    for j = 1:length(children)
        child_props = get(children(j));
        switch child_props.Type
            case 'line'
                generated_code{end+1} = sprintf('line(''XData'', %s, ''YData'', %s);', ...
                    mat2str(child_props.XData), mat2str(child_props.YData));
            case 'patch'
                generated_code{end+1} = sprintf('patch(''XData'', %s, ''YData'', %s, ''CData'', %s);', ...
                    mat2str(child_props.XData), mat2str(child_props.YData), mat2str(child_props.CData));
            % Add cases for other types of children if necessary
            otherwise
                disp(['Unhandled type: ', child_props.Type]);
        end
        
        % Set children properties (excluding data fields, set during creation)
        child_fields = fieldnames(child_props);
        for f = 1:length(child_fields)
            field_name = child_fields{f};
            if ismember(field_name, {'XData', 'YData', 'ZData', 'CData'})
                continue;
            end
            field_value = child_props.(field_name);
            if isnumeric(field_value)
                value_str = mat2str(field_value);
            else
                value_str = ['''' field_value ''''];
            end
            generated_code{end+1} = sprintf('set(gca, ''%s'', %s);', field_name, value_str);
        end
    end
end

% Display the generated code
for i = 1:length(generated_code)
    disp(generated_code{i});
end

% Save the generated code to a file
fid = fopen('generated_code.m', 'wt');
for i = 1:length(generated_code)
    fprintf(fid, '%s\n', generated_code{i});
end
fclose(fid);
