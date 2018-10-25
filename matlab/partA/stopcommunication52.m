function stopcommunication52(s)
    while 1
        fprintf(s, 'E');
        fwrite(s, 'E');
        a=fscanf(s);
        if ~isnumeric(a)
            break
        end
    end
end