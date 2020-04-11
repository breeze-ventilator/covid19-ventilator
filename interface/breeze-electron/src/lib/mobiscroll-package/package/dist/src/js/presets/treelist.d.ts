import { List } from './listbase';
import { MbscScrollerOptions } from '../classes/scroller';

export interface MbscTreelistOptions extends MbscScrollerOptions {
    defaultValue?: Array<number>;
    inputClass?: string;
    invalid?: Array<any>;
    labels?: Array<string>;
    placeholder?: string;
    showInput?: boolean;
}

export class Treelist extends List<MbscTreelistOptions> { }
