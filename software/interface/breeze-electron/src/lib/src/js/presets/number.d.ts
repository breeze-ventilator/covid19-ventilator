
import { Measurement, MbscMeasurementBaseOptions } from './measurement';

export interface MbscNumberOptions extends MbscMeasurementBaseOptions { }

export class NumberScroller extends Measurement<MbscNumberOptions> { }
