import { DatetimeBase, MbscDatetimeOptions } from './datetimebase';

export interface MbscCalbaseOptions extends MbscDatetimeOptions {
    // Settings
    calendarHeight?: number;
    calendarWidth?: number;
    calendarScroll?: 'horizontal' | 'vertical';
    counter?: boolean;
    defaultValue?: any | Array<any>;
    labels?: Array<{ start?: any, end?: any, d?: string | any, text?: string, color?: string, background?: string, cssClass?: string }>;
    events?: Array<{ start?: any, end?: any, d?: string | any, text?: string, color?: string, background?: string, cssClass?: string }>;
    marked?: Array<any | number | string | { d: any | number | string, color?: string, background?: string, cssClass?: string }>;
    colors?: Array<{ d: any | number | string, background?: string, cssClass?: string }>;
    months?: number | 'auto';
    mousewheel?: boolean;
    outerMonthChange?: boolean;
    showOuterDays?: boolean;
    tabs?: boolean;
    weekCounter?: 'year' | 'month';
    weekDays?: 'full' | 'short' | 'min';
    weeks?: number;
    yearChange?: boolean;

    // localization
    dateText?: string;
    dayNamesMin?: Array<string>;
    firstDay?: number;
    timeText?: string;
    moreEventsPluralText?: string;
    moreEventsText?: string;

    // Events
    onTabChange?(event: { tab: 'calendar' | 'date' | 'time' }, inst: any): void;
    onCellHoverIn?(event: { date: Date, marked?: any, selected?: 'start' | 'end', target: HTMLElement }, inst: any): void;
    onCellHoverOut?(event: { date: Date, marked?: any, selected?: 'start' | 'end', target: HTMLElement }, inst: any): void;
    onDayChange?(event: { date: Date, marked?: any, selected?: 'start' | 'end', target: HTMLElement }, inst: any): void;
    onLabelTap?(event: { date: Date, domEvent: any, target: HTMLElement, labels?: any[], label?: any }, inst: any): void;
    onMonthChange?(event: { year: number, month: number }, inst: any): void;
    onMonthLoading?(event: { year: number, month: number }, inst: any): void;
    onMonthLoaded?(event: { year: number, month: number }, inst: any): void;
    onPageChange?(event: { firstDay: Date, lastDay?: Date }, inst: any): void;
    onPageLoading?(event: { firstDay: Date, lastDay?: Date }, inst: any): void;
    onPageLoaded?(event: { firstDay: Date, lastDay?: Date }, inst: any): void;
    onSetDate?(event: { date: Date, control: 'calendar' | 'date' | 'time' }, inst: any): void;
}

export class CalBase<T extends MbscCalbaseOptions> extends DatetimeBase<T> {
    refresh(): void;
    redraw(): void;
    navigate(d: Date, anim?: boolean): void;
    changeTab(tab: 'calendar' | 'date' | 'time'): void;
}