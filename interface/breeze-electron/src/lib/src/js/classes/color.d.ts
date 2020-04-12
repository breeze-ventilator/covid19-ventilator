import { Frame, MbscDataFrameOptions } from './frame';

export interface MbscColorOptions extends MbscDataFrameOptions {
    // Settings
    clear?: boolean;
    data?: Array<string | { color: string }>;
    defaultValue?: string;
    enhance?: boolean;
    format?: 'hex' | 'rgb' | 'hsl';
    inputClass?: string;
    mode?: 'preset' | 'refine';
    navigation?: 'horizontal' | 'vertical';
    preview?: boolean;
    previewText?: boolean;
    rows?: number;
    valueText?: string;

    // Events
    onSet?(event: { valueText: string }, inst: any): void;
    onClear?(event: any, inst: any): void;
    onItemTap?(event: { target: HTMLElement, selected: boolean, index: number, value: string }, inst: any): void;
    onPreviewItemTap?(event: { target: HTMLElement, index: number, value: string }, inst: any): void;
}


export class Color extends Frame<MbscColorOptions> {
    setVal(val: string | Array<string>, fill?: boolean, change?: boolean, temp?: boolean): void;
    getVal(temp?: boolean): string | Array<string>;
}
