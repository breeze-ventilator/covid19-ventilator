import { Scroller, MbscScrollerOptions } from '../classes/scroller';

export interface MbscTimerOptions extends MbscScrollerOptions {
    // Settings
    autostart?: boolean;
    maxWheel?: 'years' | 'months' | 'days' | 'hours' | 'minutes' | 'seconds' | 'fract';
    mode?: 'countdown' | 'stopwatch';
    step?: number;
    targetTime?: number;
    useShortLabels?: boolean;

    // localization
    hideText?: string;
    labels?: Array<string>;
    labelsShort?: Array<string>;
    lapText?: string;
    resetText?: string;
    startText?: string;
    stopText?: string;

    // Events
    onLap?(event: { ellapsed: number, lap: number, laps: Array<number> }, inst: any): void;
    onFinish?(event: { time: number }, inst: any): void;
    onReset?(event: any, inst: any): void;
    onStart?(event: any, inst: any): void;
    onStop?(event: { ellapsed: number }, inst: any): void;
}

export class Timer extends Scroller<MbscTimerOptions> {
    handlers: {
        set: () => void,
        cancel: () => void,
        clear: () => void
        toggle: () => void,
        start: () => void,
        stop: () => void,
        resetLap: () => void,
        reset: () => void,
        lap: () => void
    };
    buttons: {
        toggle: any,
        start: any,
        stop: any,
        reset: any,
        lap: any,
        resetLap: any,
        hide: any
    };

    start(): void;
    stop(): void;
    toggle(): void;
    reset(): void;
    lap(): void;
    resetLap(): void;
    getTime(): number;
    setTime(t: number): void;
    getEllapsedTime(): number;
    setEllapsedTime(t: number, change?: boolean): void;
}