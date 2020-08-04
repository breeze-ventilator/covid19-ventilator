import { NavigationBase, MbscNavBaseOptions } from './navigation-base';

export interface MbscOptionlistOptions extends MbscNavBaseOptions {
    // Settings
    paging?: boolean;
    select?: 'single' | 'multiple' | 'off';
    snap?: boolean;
    type?: 'options' | 'tabs' | 'menu';
    variant?: 'a' | 'b';
    threshold?: number;
}

export class Optionlist extends NavigationBase<MbscOptionlistOptions> { }
