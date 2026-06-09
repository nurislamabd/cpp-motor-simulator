% Load both datasets
cpp_data    = readtable('motor_data.csv');
matlab_data = readtable('matlab_sim_output.csv');

figure;
tiledlayout(1,2);

% --- Plot 1: C++ vs MATLAB position ---
nexttile
plot(cpp_data.Time, cpp_data.Position_steps, 'b-');
hold on;
plot(matlab_data.Time, matlab_data.Position_steps, 'r--');
xlabel('Time (ms)');
ylabel('Steps');
legend('C++', 'MATLAB sim');
title('C++ vs MATLAB Motor Steps');
grid on;

% --- Plot 2: Error ---
cpp_interp = interp1(cpp_data.Time, ...
                     cpp_data.Position_steps, ...
                     matlab_data.Time);
error = cpp_interp - matlab_data.Position_steps;

nexttile
plot(matlab_data.Time, error, 'k');
xlabel('Time (ms)');
ylabel('Error (steps)');
title('Position Error');
grid on;