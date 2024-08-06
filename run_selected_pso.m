function [global_best, eq_step, stio] = run_selected_pso(soc, run_number)

    switch run_number
        case 1
            [global_best, eq_step, stio] = pso(soc, 2, 0.1, 0.8, 0.1);
        case 2
            [global_best, eq_step, stio] = pso(soc, 2, 0.5, 0.5, 0.0);
        case 3
            [global_best, eq_step, stio] = pso(soc, 2, 0.0, 0.5, 0.5);
        case 4
            [global_best, eq_step, stio] = pso(soc, 2, 0.33, 0.33, 0.33);
        case 9
            [global_best, eq_step, stio] = pso(soc, 2, 0.3,0.6,0.1);
        case 10
            % a novel GA
            [global_best, eq_step, stio] = pso(soc, 2, 0.2,0.8,0.0);

        otherwise
            error('Invalid run number. Please select a number between 1 and 4.');
    end
end