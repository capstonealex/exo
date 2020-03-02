function [m] = getMotorSpecs()
    m.torqueConstant    = 114e-3;   % in [Nm/A] from Maxon - 412825 datasheet
    
    m.stallTorque       = 5010e-3;   % in [Nm]  from Maxon - 412825 datasheet
    m.stallCurrent      = 43.8;      % [A]
    m.noLoadSpeed       = 3970;      % RPM 
    
    m.nominalCurrent    = 2.78;     % [A]   max continuous current
    m.nominalTorque     = 319e-3;   % [Nm]  max continuous torque
    
    m.speedTorqueSlope  = 798;      % [RPM/Nm]
    
    m.maxCurrentDrivers = 6;        % [A]
    
    m.GR                = 122.5;    % Gear ratio, not really motor spec, but approriate calculations
end