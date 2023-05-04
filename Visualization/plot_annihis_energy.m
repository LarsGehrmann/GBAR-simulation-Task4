function plot_annihis_energy()

set(0,'defaultTextInterpreter','latex');
set(0, 'defaultLegendInterpreter','latex');
set(0, 'defaultAxesTickLabelInterpreter','latex');

noEnergies = 31;
EStartLog = -2.; % MeV
EEndLog = 1.; % MeV
energies = logspace(EStartLog, EEndLog, noEnergies);

modThickness = [100, 200, 500, 14000]; % total moderator is 1cm thick, modThickness means front of moderator
dirStart = "\\wsl.localhost\Ubuntu\home\lars\Geant4\Task4\build\";
dirEnd = "_nt_Annihilations.csv";

noAnnihis = zeros(4,noEnergies);
for i=1:4
    for j=0:noEnergies-1
        dir = dirStart + string(modThickness(i)) + "micron" + string(j) + dirEnd;
        M = dlmread(dir, ',', 8, 0);
        noAnnihis(i,j+1) = length(M);
    end
end


colors = ["r", "b", "k", "m"];
powLawRegions = [10, 11, 14, 24];
noDecimals = 3;
figure
for i=1:4
    loglog(energies, noAnnihis(i,:), colors(i)+"X")
    [X,Y,R2,C] = myLinReg(log(energies(powLawRegions(i):end)),log(noAnnihis(i,(powLawRegions(i):end))));
    format long
    format short
    R2 = round(10^noDecimals * R2) / 10^noDecimals;
    legendHelp(2*i-1) = "$d\textrm{Front} = $" + string(modThickness(i)) + "$\mu \textrm{m}$";
    legendHelp(2*i) = "$\textrm{Quadratic fit } r^2 = $" + string(R2);
    hold on
    plot(exp(X),exp(Y), colors(i))
end
legend(legendHelp, 'Location', 'Southwest')
grid on
xlabel('$E / \textrm{MeV}$')
ylabel('$\textrm{No annihilations}$')
titleHelp = {"$\textbf{No annihilations in neon-cylinder as a function of different }$",...
    "$\textbf{positron energies for different moderator front thicknesses}$"};
title(titleHelp)

end