import { Scroller, MbscScrollerOptions } from '../classes/scroller';
import { MbscDataControlOptions } from '../classes/frame';
import '../util/requests';

export type MbscDataScrollerOptions = MbscDataControlOptions & MbscScrollerOptions;

export interface MbscSelectOptions extends MbscDataScrollerOptions {
    // Settings
    counter?: boolean;
    data?: Array<{ text?: string, value?: any, group?: string, html?: string, disabled?: boolean }> | {
        url: string,
        dataField?: string,
        dataType?: 'json' | 'jsonp',
        processResponse?: (data: any) => Array<{ text?: string, value?: any, group?: string, html?: string, disabled?: boolean }>,
        remoteFilter?: boolean
    };
    dataText?: string;
    dataGroup?: string;
    dataValue?: string;
    filter?: boolean;
    filterPlaceholderText?: string;
    filterEmptyText?: string;
    group?: boolean | { header?: boolean, groupWheel?: boolean, clustered?: boolean };
    groupLabel?: string;
    input?: string | object;
    inputClass?: string;
    invalid?: Array<any>;
    label?: string;
    placeholder?: string;
    showInput?: boolean;
    onFilter?(event: { filterText: string }, inst: any): false | void;
}

export class Select extends Scroller<MbscSelectOptions> {
    setVal(val: string | number | Array<string | number>, fill?: boolean, change?: boolean, temp?: boolean, time?: number): void;
    getVal(temp?: boolean, group?: boolean): string | number | Array<string | number>;
    refresh(data?: Array<{ text?: string, value?: any, group?: string, html?: string, disabled?: boolean }>, filter?: string, callback?: () => void): void;
}
