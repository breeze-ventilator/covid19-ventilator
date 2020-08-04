import { Measurement } from './measurement';
import { MbscTemperatureOptions } from './temperature';

export interface MbscDistanceOptions extends MbscTemperatureOptions { }

export class Distance extends Measurement<MbscDistanceOptions> { }
