import { NavigationBase, MbscNavBaseOptions } from './navigation-base';

export interface MbscNavOptions extends MbscNavBaseOptions {
    type: 'bottom' | 'hamburger' | 'tab';
    moreText?: string;
    moreIcon?: string;
    menuText?: string;
    menuIcon?: string;
    onMenuHide?(event: { target: HTMLElement, menu: any }, inst: any): void;
    onMenuShow?(event: { target: HTMLElement, menu: any }, inst: any): void;
}

export class Navigation extends NavigationBase<MbscNavOptions> { }
