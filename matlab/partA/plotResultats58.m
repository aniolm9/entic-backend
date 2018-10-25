function plotResultats58(fitxer)
    vector = [];
    temps = [];
    mesures = [];
    
    f = fopen(fitxer, 'r');
    lectura = textscan(f, '%s %f');
    
    for elm = lectura{2}.'
        if ~isnan(elm)
            vector = [vector, elm];
        end
    end
    
    temps = vector(1:500);
    mesures = vector(501:1000);
    
    figure
    ylim([-3 1])
    hold on
    plot(temps, mesures);
    fclose(f);
end