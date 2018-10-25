function endcommunication51(s)
    fclose(s);
    delete(s);
    clear s;
    instrreset;
end
