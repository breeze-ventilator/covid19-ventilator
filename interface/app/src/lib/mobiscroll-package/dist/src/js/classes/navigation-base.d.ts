import { ScrollView, MbscScrollViewOptions } from './scrollview';

export interface MbscNavBaseOptions extends MbscScrollViewOptions {
    display?: 'top' | 'bottom' | 'inline';
}

export class NavigationBase<T extends MbscNavBaseOptions = MbscNavBaseOptions> extends ScrollView<T> {
    select(item: any): void;
    deselect(item: any): void;
    enable(item: any): void;
    disable(item: any): void;
    setBadge(item: any, content: string): void;
}