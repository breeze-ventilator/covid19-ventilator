import { MbscDataControlOptions } from '../classes/frame';
import { CalBase, MbscCalbaseOptions } from './calbase';

export type MbscDataCalbaseOptions = MbscDataControlOptions & MbscCalbaseOptions;

export interface MbscEventcalendarOptions extends MbscDataCalbaseOptions {
    // Settings
    data?: Array<{ start?: any, end?: any, d?: any | string | number, text?: string, color?: string, allDay?: boolean }>;
    eventBubble?: boolean;
    formatDuration?(start: Date, end: Date): string;
    showEventCount?: boolean;
    view?: {
        calendar?: { type?: 'week' | 'month', size?: number, popover?: boolean, labels?: boolean },
        eventList?: { type?: 'day' | 'week' | 'month' | 'year', size?: number, scrollable?: boolean }
    };
    // Localization
    allDayText?: string;
    noEventsText?: string;
    eventText?: string;
    eventsText?: string;
    labelsShort?: Array<string>;
    // Events
    onEventSelect?(event: { event: any, date: Date, domEvent: any }, inst: Eventcalendar): void;
    onCellHoverIn?(event: { events: Array<{ start?: any, end?: any, d?: any | string | number, text?: string, color?: string, allDay?: boolean }>, date: Date, marked?: any, selected?: 'start' | 'end', target: HTMLElement }, inst: any): void;
    onCellHoverOut?(event: { events: Array<{ start?: any, end?: any, d?: any | string | number, text?: string, color?: string, allDay?: boolean }>, date: Date, marked?: any, selected?: 'start' | 'end', target: HTMLElement }, inst: any): void;
    onDayChange?(event: { events: Array<{ start?: any, end?: any, d?: any | string | number, text?: string, color?: string, allDay?: boolean }>, date: Date, marked?: any, selected?: 'start' | 'end', target: HTMLElement }, inst: any): void;
}

export class Eventcalendar extends CalBase<MbscEventcalendarOptions> {
    navigate(d: Date, anim?: boolean, pop?: boolean): void;
    addEvent(events: Array<{ start?: any, end?: any, d?: any | string | number, text?: string, color?: string, allDay?: boolean }> | { start?: any, end?: any, d?: any | string | number, text?: string, color?: string, allDay?: boolean }): Array<number | string>;
    updateEvent(event: { start?: any, end?: any, d?: any | string | number, text?: string, color?: string, allDay?: boolean }): void;
    removeEvent(eids: Array<string | number>): void;
    getEvents(d: Date): Array<{ start?: any, end?: any, d?: any | string | number, text?: string, color?: string, allDay?: boolean }>;
    setEvents(events: Array<{ start?: any, end?: any, d?: any | string | number, text?: string, color?: string, allDay?: boolean }> | { start?: any, end?: any, d?: any | string | number, text?: string, color?: string, allDay?: boolean }): Array<number | string>;
}