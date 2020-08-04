import { Measurement } from './measurement';
import { MbscTemperatureOptions } from './temperature';

export interface MbscForceOptions extends MbscTemperatureOptions { }

export class Force extends Measurement<MbscForceOptions> { }
