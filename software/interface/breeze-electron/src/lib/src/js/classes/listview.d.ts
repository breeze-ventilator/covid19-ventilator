import { Base, MbscCoreOptions } from '../core/core';

export interface MbscListviewOptions extends MbscCoreOptions {
    actions?: Array<any> | { left?: any, right?: any };
    actionsWidth?: number;
    context?: string | HTMLElement;
    striped?: boolean;
    animateIcons?: boolean;
    animateAddRemove?: boolean;
    actionable?: boolean;
    enhance?: boolean;
    fillAnimation?: boolean;
    fixedHeader?: boolean;
    hover?: 'left' | 'right' | { direction?: 'left' | 'right', time?: number, timeout?: number };
    iconSlide?: boolean;
    itemGroups?: any;
    navigateOnDrop?: boolean;
    quickSwipe?: boolean;
    sortable?: boolean | { group?: boolean, handle?: boolean | 'left' | 'right', multilevel?: boolean };
    sortDelay?: number;
    stages?: Array<any> | { left?: Array<any>, right?: Array<any> };
    swipe?: boolean | 'left' | 'right' | ((args: { target: HTMLElement, index: number, direction: 'left' | 'right' }, inst: any) => (boolean | 'left' | 'right'));
    swipeleft?(): void;
    swiperight?(): void;
    vibrate?: boolean;
    loadingIcon?: string;
    select?: 'off' | 'single' | 'multiple';

    // localization
    undoText?: string;
    backText?: string;

    // Events
    onItemTap?(event: { target: HTMLElement, domEvent: any, index: number }, inst: any): void;
    onItemAdd?(event: { target: HTMLElement }, inst: any): void;
    onItemRemove?(event: { target: HTMLElement }, inst: any): void;
    onNavEnd?(event: { level: number, direction: 'left' | 'right', list: HTMLElement }, inst: any): void;
    onNavStart?(event: { level: number, direction: 'left' | 'right', list: HTMLElement }, inst: any): void;
    onSlideEnd?(event: { target: HTMLElement, index: number }, inst: any): void;
    onSlideStart?(event: { target: HTMLElement, index: number }, inst: any): void;
    onSort?(event: { target: HTMLElement, index: number }, inst: any): void;
    onSortChange?(event: { target: HTMLElement, index: number }, inst: any): void;
    onSortStart?(event: { target: HTMLElement, index: number }, inst: any): void;
    onSortEnd?(event: { target: HTMLElement, index: number }, inst: any): void;
    onSortUpdate?(event: { target: HTMLElement, index: number }, inst: any): void;
    onStageChange?(event: { target: HTMLElement, index: number, stage: any }, inst: any): void;
    onListEnd?(event: {}, inst: any): void;
}

export class ListView extends Base<MbscListviewOptions> {
    animate(li: any, anim: string, callback?: (ul: any, li: any) => void): void;
    add(id: string | number, markup: string, index?: number, callback?: (ul: any, li: any) => void, parent?: any, isUndo?: boolean): void;
    swipe(li: any, percent: number, time?: number, demo?: boolean, callback?: () => void): void;
    openStage(li: any, stage: string, time?: number, demo?: boolean): void;
    openActions(li: any, dir: 'left' | 'right', time?: number, demo?: boolean): void;
    close(li: any, time?: number): void;
    remove(li: any, dir?: 'left' | 'right', callback?: (ul: any, li: any) => void, isUndo?: boolean): void;
    move(li: any, index: number, direction?: 'left' | 'right', callback?: (ul: any, li: any) => void, parent?: any, isUndo?: boolean): void;
    navigate(li: any, callback?: (ul: any, li: any) => void): void;
    startActionTrack(): void;
    endActionTrack(): void;
    addUndoAction(action: any, async?: boolean): void;
    undo(): void;
    hideLoading(): void;
    showLoading(): void;
    select(li: any): void;
    deselect(li: any): void;
}