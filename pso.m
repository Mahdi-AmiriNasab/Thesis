
function [global_best, eq_step, stio] = pso(soc_in, mp, w_time, w_inconsistency, w_eq_overlap)

%% problem definition
costfunction = @(ep) balance_costF(soc_in, mp, ep, w_time, w_inconsistency, w_eq_overlap);  % cost function 

nvar = 1;                       % number of unknown (decision) variables

varsize = [1 nvar];             % matrix size of decision variables
varmin = 0.1;                   % lower bound of dicision of variables
varmax = 20;                    % upper bound of dicision of variables

%% parameters of PSO
maxit   = 20;        % maximum itteration 

npop    = 10;       % population size
w       = 1;        % inertia coefficient
wdamp   = 0.99;     % inertia damping ratio coefficient
c1      = 2;             % personal acceleration coefficient 
c2      = 2;             % social acceleration coefficient

%% initialization

% the particel template
empty_particle.position = [];
empty_particle.cost = [];
empty_particle.best.position = [];
empty_particle.best.cost = [];

% create population array
particle = repmat(empty_particle, npop, 1);

% global best

global_best.cost = inf;
% start with the +infinity value to move toward least values...
% (this is the worst value) 


for i=1:npop
    % generate randon solution
    particle(i).position = unifrnd(varmin, varmax, varsize);

    % initialize velocity
    particle(i).velocity = zeros(varsize);

    % evaluation 
    [particle(i).cost, eq_step, stio.soc, stio.time, stio.inconsistency, stio.eq_overlap] = costfunction(particle(i).position);

    %update the personal best
    particle(i).best.position = particle(i).position;
    particle(i).best.cost = particle(i).cost;

    %update global best
    if(particle(i).best.cost < global_best.cost)
        global_best = particle(i).best;
    end
end

% array to hold best costs
best_costs = zeros(maxit, 1);

%% main loop of PSO
for it=1:maxit  
    for i=1:npop

        % update velocity
        particle(i).velocity = w*particle(i).velocity...
            + c1*rand(varsize).*(particle(i).best.position - particle(i).position)...
            + c2*rand(varsize).*(global_best.position - particle(i).position);

        % update position
        particle(i).position = particle(i).position + particle(i).velocity;
        
        % limitation
        particle(i).position = max(particle(i).position, varmin);
        particle(i).position = min(particle(i).position, varmax);
        

        % evaluation
        [particle(i).cost, eq_step, stio.soc, stio.time, stio.inconsistency, stio.eq_overlap] = costfunction(particle(i).position);

        % update personal best
        if(particle(i).cost < particle(i).best.cost)

            particle(i).best.cost = particle(i).cost;
            particle(i).best.position = particle(i).position;

            %update global best
            if(particle(i).best.cost < global_best.cost)
                global_best = particle(i).best;
            end
        
        end
    end
    % store the best cost value
    best_costs(it) = global_best.cost;
    % display the iteration information
    disp(['iteration ' num2str(it) ': best cost = ' num2str(best_costs(it))]);
    % scatter3(global_best.position(1, 1), global_best.position(1, 2), global_best.position(1, 3));
    w = w * wdamp;

end
%% results

figure;
plot(best_costs);
xlabel('iteration');
ylabel('best cost');

end

