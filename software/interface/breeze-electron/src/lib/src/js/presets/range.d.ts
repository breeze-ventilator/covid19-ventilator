import { CalBase, MbscCalbaseOptions } from './calbase';

export interface MbscRangeOptions extends MbscCalbaseOptions {
    // Settings
    autoCorrect?: boolean;
    controls?: Array<'time' | 'date' | 'calendar'>;
    endInput?: string | HTMLElement;
    maxRange?: number;
    minRange?: number;
    showSelector?: boolean;
    startInput?: string | HTMLElement;

    // localization
    fromText?: string;
    toText?: string;

    // Events
    onSetDate?(event: { date: Date, active: 'start' | 'end', control: 'calendar' | 'date' | 'time' }, inst: any): void;
}

export class RangePicker extends CalBase<MbscRangeOptions> {
    startVal: string;
    endVal: string;
    setVal(values: Array<any>, fill?: boolean, change?: boolean, temp?: boolean, time?: number): void;
    getVal(temp?: boolean): Array<any>;
    setActiveDate(active: 'start' | 'end'): void;
}