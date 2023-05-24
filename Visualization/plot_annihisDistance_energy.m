function plot_annihisDistance_energy()
fontSizeLegend = 10;
fontSizeAxes = 12;
set(0,'defaultTextInterpreter','latex');
set(0, 'defaultLegendInterpreter','latex');
set(0, 'defaultAxesTickLabelInterpreter','latex');

noEnergies = 31;
EStartLog = -2.; % MeV
EEndLog = 1.; % MeV
energies = logspace(EStartLog, EEndLog, noEnergies);
noDecimals = 4;


modThickness = [15, 100, 200, 500, 14000];
noThicknesses = length(modThickness);
dirStart = "\\wsl.localhost\Ubuntu\home\lars\Geant4\Task4\build\";
dirEnd = "_nt_Annihilations.csv";

noAnnihisDistance = zeros(noThicknesses,noEnergies);
for i=1:noThicknesses
    for j=0:noEnergies-1
        dir = dirStart + string(modThickness(i)) + "micron" + string(j) + dirEnd;
        M = dlmread(dir, ',', 8, 0);
        sz = size(M);
        if i == 1 && j == 30
            a = 3;
        end
        for k=1:sz
            noAnnihisDistance(i,j+1) = noAnnihisDistance(i,j+1) + sqrt( (M(k,3)^2) ); % cylinder starts at z = 0 therefore distance is z-component
            %noAnnihisDistance(i,j+1) = noAnnihisDistance(i,j+1) + sqrt( (M(k,1)^2) + M(k,2)^2 );
        end
        noAnnihisDistance(i,j+1) = noAnnihisDistance(i,j+1) / length(M);
    end
end


colors = ["r", "b", "k", "m","c"];
figure
for i=1:noThicknesses
    loglog(energies, noAnnihisDistance(i,:), colors(i) + "X")
    legendHelp(i) = "$d\textrm{Front} = $" + string(modThickness(i)) + "$\mu \textrm{m}$";
    hold on
end

[X,Y,R2,C] = myLinReg(log(energies(1:24)),log(noAnnihisDistance(end,1:24)));
format long
C
format short
R2 = round(10^noDecimals*R2)/10^noDecimals;

plot(exp(X),exp(Y),colors(end))
legendHelp(end+1) = "$\textrm{Fit: } r^2 = $" + string(R2);

legend(legendHelp,'Location', 'South')
grid on
xlabel('$E / \textrm{MeV}$')
ylabel('$\textrm{dist} / \textrm{mm}$')
titleHelp = {"$\textbf{Average distances of annihlation locaitons to surface in neon-cylinder}$", ...
    "$\textbf{as a function of different positron energies for different}$",...
    "$\textbf{moderator front thicknesses}$"};
%title(titleHelp)
hLegend = findobj(gcf, 'Type', 'Legend');
set(hLegend,'FontSize', fontSizeLegend)
hAxis = findobj(gcf,'Type','Axes')
set(hAxis,'FontSize', fontSizeAxes)
end