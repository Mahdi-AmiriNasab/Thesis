%% start clustering

clear all;
close all;
cell_count = 9;
cell_cap_Ah = 2.2;

%soc = [39    39    20    72    81    92    51    11    60]; % good one

%soc = [1    10    20    30    40    50    50    50    50]; % test

%soc = [10    10    10   7     10     9    9   9    15]; % test

%soc = fix(rand (1, cell_count) * 100);

%soc = [62	58	96	8	50	52	9	90	88];
soc = [16   16  50  27  27  23  22  73  73]; % main article

% Research on two-stage equalization strategy based on fuzzy logic control for lithium-ion battery packs
%soc = [76   73  71  68  64  62  60  58  57]; 

if any(soc == 0)
    error("soc equal to 0 is not supported")
end
soc_init = soc;

mp = 2;
ep = 1;

itteration = 0;
soc_transfered_total = 0;
blc_time_total = 0;

ep_domain = 0.1:0.1:20;

global no_ovp_plot_flag;

lg_time = zeros(length(ep_domain), 1);
lg_inconsistency = zeros(length(ep_domain), 1);
lg_eq_overlap = zeros(length(ep_domain), 1);
[lg_time, lg_inconsistency, lg_eq_overlap, ~] = log_clustering(soc, mp, ep_domain);
no_ovp_plot_flag = 0;

% select the run number you want to execute


run_number = 9; [global_best, eq_step, stio] = run_selected_pso(soc, run_number);
%[global_best, eq_step, stio] = pso(soc, 2, 0.2,0.7,0.1);
%[cost, eq_step, soc, time, inconsistency, eq_overlap] = balance_costF(soc_init, 2, 0.400, 0, 0, 0);global_best.position = 0.400;

src_q_cls = zeros(50, 2);
dst_q_cls = zeros(50, 2);
src_trg_soc_av = zeros(50, 1);
dst_trg_soc_av = zeros(50, 1);

% plot the final result obtained using PSO
[eq_step, stio.soc, stio.time, stio.inconsistency, stio.eq_overlap] = plot_final(soc_init, mp, global_best.position, ep_domain, lg_time, lg_inconsistency, lg_eq_overlap);

% Save all open figures in the dedicated folder for the current run
folder_name = sprintf('run%d', run_number);
if ~exist(folder_name, 'dir')
    mkdir(folder_name);
end
figHandles = findall(0, 'Type', 'figure');
for i = 1:length(figHandles)
    fig = figHandles(i);
    set(fig, 'Units', 'normalized', 'OuterPosition', [0 0 1 1]); % Maximize the figure
    fig_name = get(fig, 'Name'); % Get the name of the figure
    if isempty(fig_name)
        fig_name = sprintf('figure%d', i); % Default name if no name is set
    end
    saveas(fig, fullfile(folder_name, [fig_name, '.fig']));
    saveas(fig, fullfile(folder_name, [fig_name, '.png'])); % Save as PNG for easier viewing
end


%% preparing output steps for for matlab simulink file
for n = 1:length(eq_step)
    src_q_cls(n, :) = eq_step(n).source_queue_cells;
    dst_q_cls(n, :) = eq_step(n).destination_queue_cells;
    src_trg_soc_av(n, 1) = eq_step(n).source_target_soc_av;
    dst_trg_soc_av(n, 1) = eq_step(n).destination_target_soc_av;
end

clear figHandles fig
% Save the current workspace
save(fullfile(folder_name, 'workspace.mat'));
