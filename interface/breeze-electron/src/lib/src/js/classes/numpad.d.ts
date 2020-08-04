import { Frame, MbscFrameOptions } from './frame';
import '../util/datetime';

export interface MbscNumpadOptions extends MbscFrameOptions {
    // Settings
    allowLeadingZero?: boolean;
    deleteIcon?: string;
    fill?: 'ltr' | 'rtl';
    leftKey?: { text: string, variable?: string, value?: string, keys?: number[] };
    mask?: string;
    placeholder?: string;
    rightKey?: { text: string, variable?: string, value?: string, keys?: number[] };
    template?: string;
    preset?: 'date' | 'time' | 'decimal' | 'timespan';

    // Events
    onSet?(event: { valueText: string }, inst: any): void;
    validate?(data: { values: Array<any>, variables: any }, inst: any): ({ disabled?: Array<any>, invalid?: boolean });
    onClear?(event: any, inst: any): void;
    onInput?(event: { domEvent: any, target: any, values: Array<any>, valueText: string, variables: any }, inst: any): void;

    // localization
    cancelText?: string;
    clearText?: string;
    setText?: string;

    formatValue?(numbers: Array<any>, variables: any, inst: any): string;
    parseValue?(valueText: string): any;
}

export interface MbscNumpadDecimalOptions extends MbscNumpadOptions {
    decimalSeparator?: string;
    defaultValue?: number;
    entryMode?: 'template' | 'freeform';
    invalid?: Array<any>;
    scale?: number;
    maxScale?: number;
    min?: number;
    max?: number;
    prefix?: string;
    preset?: 'decimal';
    returnAffix?: boolean;
    suffix?: string;
    thousandsSeparator?: string;
}

export interface MbscNumpadDateOptions extends MbscNumpadOptions {
    dateFormat?: string;
    dateOrder?: string;
    delimiter?: string;
    defaultValue?: string;
    invalid?: Array<any>;
    min?: Date;
    max?: Date;
    preset?: 'date';
}

export interface MbscNumpadTimeOptions extends MbscNumpadOptions {
    defaultValue?: string;
    invalid?: Array<any>;
    max?: Date;
    min?: Date;
    preset?: 'time';
    timeFormat?: string;
}

export interface MbscNumpadTimespanOptions extends MbscNumpadOptions {
    defaultValue?: number;
    invalid?: Array<any>;
    min?: number;
    max?: number;
    preset?: 'timespan';
}

export class Numpad extends Frame<MbscNumpadOptions> {
    setVal(val: string | number | Date, fill?: boolean, change?: boolean, temp?: boolean): void;
    getVal(temp?: boolean): string | number | Date;
    setArrayVal(val: Array<any>, fill?: boolean, change?: boolean, temp?: boolean): void;
    getArrayVal(temp?: boolean): Array<any>;
}
