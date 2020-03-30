import { Scroller, MbscScrollerOptions } from '../classes/scroller';

export interface MbscTimespanOptions extends MbscScrollerOptions {
    // Settings
    defaultValue?: number;
    max?: number;
    min?: number;
    steps?: Array<number>;
    useShortLabels?: boolean;
    wheelOrder?: string;
    labels?: Array<string>;
    labelsShort?: Array<string>;
}

export class Timespan extends Scroller<MbscTimespanOptions> {
    getVal(temp?: boolean, formatted?: boolean): number;
}