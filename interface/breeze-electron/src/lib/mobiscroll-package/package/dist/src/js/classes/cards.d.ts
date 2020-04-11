import { Base, MbscCoreOptions } from '../core/core';

export interface MbscCardOptions extends MbscCoreOptions {
    collapsible?: boolean
}

export class Card extends Base<MbscCardOptions> {
    // methods
    refresh(shallow?: boolean): void;
    toggle?(): void;
    hide?(): void;
    show?(): void;
}

