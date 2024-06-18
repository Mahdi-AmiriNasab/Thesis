function [global_best, eq_step, stio] = run_selected_pso(soc, run_number)

    switch run_number
        case 1
            [global_best, eq_step, stio] = pso(soc, 2, 0.33, 0.33, 0.33);
        case 2
            [global_best, eq_step, stio] = pso(soc, 2, 0.1, 0.8, 0.1);
        case 3
            [global_best, eq_step, stio] = pso(soc, 2, 0.1, 0.1, 0.8);
        case 4
            [global_best, eq_step, stio] = pso(soc, 2, 0.3, 0.6, 0.1);
        case 5
            [global_best, eq_step, stio] = pso(soc, 2, 0.1, 0.3, 0.6);
        case 6
            [global_best, eq_step, stio] = pso(soc, 2, 0.3, 0.1, 0.6);
        case 7
            [global_best, eq_step, stio] = pso(soc, 2, 0.1, 0.2, 0.7);
        case 8
            [global_best, eq_step, stio] = pso(soc, 2, 0.4, 0.4, 0.2);
        case 9
            [global_best, eq_step, stio] = pso(soc, 2, 0.2, 0.4, 0.4);
        otherwise
            error('Invalid run number. Please select a number between 1 and 9.');
    end
end