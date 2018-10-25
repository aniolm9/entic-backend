function startcommunication52(s)
    while 1
        fprintf(s, 'S');
        fwrite(s, 'S');
        a=fscanf(s, '%d');
        if isnumeric(a)
            break
        end
    end
end

