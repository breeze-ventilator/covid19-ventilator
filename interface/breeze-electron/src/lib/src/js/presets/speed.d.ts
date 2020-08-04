import { Measurement } from './measurement';
import { MbscTemperatureOptions } from './temperature';

export interface MbscSpeedOptions extends MbscTemperatureOptions { }

export class Speed extends Measurement<MbscSpeedOptions> { }
