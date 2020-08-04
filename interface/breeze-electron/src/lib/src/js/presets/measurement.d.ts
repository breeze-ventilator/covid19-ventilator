import { Scroller, MbscScrollerOptions } from '../classes/scroller';

export interface MbscMeasurementBaseOptions extends MbscScrollerOptions {
    // Settings
    max?: number;
    min?: number;
    decimalSeparator?: string;
    defaultValue?: string;
    invalid?: Array<any>;
    scale?: number;
    step?: number;
    units?: Array<string>;

    // localization
    wholeText?: string;
    fractionText?: string;
    signText?: string;
}

export interface MbscMeasurementOptions extends MbscMeasurementBaseOptions {
    // Settings
    convert?(val: number, unit1: string, unit2: string): number;
}

export class Measurement<T extends MbscMeasurementBaseOptions = MbscMeasurementOptions> extends Scroller<T> { }
