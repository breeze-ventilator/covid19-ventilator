import { Measurement, MbscMeasurementBaseOptions } from './measurement';

export interface MbscTemperatureOptions extends MbscMeasurementBaseOptions {
    // Settings
    convert?: boolean;
    defaultUnit?: string;
    unitNames?: any;
}

export class Temperature extends Measurement<MbscTemperatureOptions> { }
