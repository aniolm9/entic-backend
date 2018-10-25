function [t,mitjanes] = toDepth54(s)
    b = [];
    t = [];
    mitjanes = [];
    
    figure
    ylim([-3 1])
    hold on
    
    for i = 0:999
        b = [b,(fscanf(s,'%d')-682)/-71];
        if i<=10
            mitjanes = b;
        else
            mitjanes = [mitjanes, mean(b(i-10:i))];
        end
        t = [t, i*0.2];
        plot(t,mitjanes,'b');drawnow
    end    
end


