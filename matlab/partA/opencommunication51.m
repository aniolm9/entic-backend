function [s] = opencommunication51()
    s = serial('COM7');
    set(s,'BaudRate',9600, 'Terminator', 'CR/LF');
    fopen(s);
end