function toText55(temps, mesures)
    f = fopen('resultats.txt', 'w+');
    t = sprintf('%d ', temps);
    m = sprintf('%d ', mesures);
    fprintf(f,'Time: %s\nMesures: %s\n', t, m);
    fclose(f);
end

