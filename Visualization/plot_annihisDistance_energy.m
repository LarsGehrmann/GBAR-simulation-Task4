function plot_annihisDistance_energy()

set(0,'defaultTextInterpreter','latex');
set(0, 'defaultLegendInterpreter','latex');
set(0, 'defaultAxesTickLabelInterpreter','latex');

noEnergies = 20;
EStart = 100; % keV
EStep = 100; % keV
energies = EStart:EStep:EStart+(noEnergies-1)*EStep;


modThickness = [100, 200, 500];
dirStart = "\\wsl.localhost\Ubuntu\home\lars\Geant4\Task4\build\";
dirEnd = "_nt_Annihilations.csv";

noAnnihisDistance = zeros(3,noEnergies);
for i=1:3
    for j=0:noEnergies-1
        dir = dirStart + string(modThickness(i)) + "micron" + string(j) + dirEnd;
        M = dlmread(dir, ',', 8, 0);
        for k=1:length(M)
            noAnnihisDistance(i,j+1) = noAnnihisDistance(i,j+1) + sqrt( (M(k,1)^2) + M(k,2)^2 );
        end
        noAnnihisDistance(i,j+1) = noAnnihisDistance(i,j+1) / length(M);
    end
end


colors = ["r", "b", "k"];
figure
for i=1:3
    plot(energies / 1000, noAnnihisDistance(i,:), colors(i) + "X")
    legendHelp(i) = "$d\textrm{Front} = $" + string(modThickness(i)) + "$\mu \textrm{m}$";
    hold on
end
legend(legendHelp,'Location', 'Northwest')
grid on
xlabel('$E / \textrm{MeV}$')
ylabel('$\textrm{dist} / \textrm{mm}$')
titleHelp = {"$\textbf{Average distances of annihlation locaitons to surface in neon-cylinder}$", ...
    "$\textbf{as a function of different positron energies for different}$",...
    "$\textbf{moderator front thicknesses}$"};
title(titleHelp)
end