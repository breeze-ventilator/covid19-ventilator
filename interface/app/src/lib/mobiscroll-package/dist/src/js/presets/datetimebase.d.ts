import { Scroller, MbscScrollerOptions } from '../classes/scroller';
import '../util/datetime';

export interface MbscDatetimeOptions extends MbscScrollerOptions {
    // Settings
    defaultValue?: any | Array<any>;
    invalid?: Array<string | { start: any, end: any, d?: string } | any>;
    max?: any;
    min?: any;
    returnFormat?: 'iso8601' | 'moment' | 'locale' | 'jsdate';
    steps?: { hour?: number, minute?: number, second?: number, zeroBased?: boolean };
    valid?: Array<string | { start: any, end: any, d?: string } | any>;
    calendarSystem?: 'jalali' | 'hijri' | 'gregorian';
    moment?: any;

    // localization
    ampmText?: string;
    amText?: string;
    dateFormat?: string;
    dateWheels?: string;
    dayNames?: Array<string>;
    dayNamesShort?: Array<string>;
    dayText?: string;
    hourText?: string;
    minuteText?: string;
    monthNames?: Array<string>;
    monthNamesShort?: Array<string>;
    monthSuffix?: string;
    monthText?: string;
    nowText?: string;
    pmText?: string;
    secText?: string;
    timeFormat?: string;
    timeWheels?: string;
    yearSuffix?: string;
    yearText?: string;
}

export class DatetimeBase<T extends MbscDatetimeOptions = MbscDatetimeOptions> extends Scroller<T> {
    handlers: {
        set: () => void,
        cancel: () => void,
        clear: () => void
        now: () => void
    };

    getDate(temp?: boolean): Date | null;
    setDate(date: Date, fill?: boolean, time?: number, temp?: boolean, change?: boolean): void;
}