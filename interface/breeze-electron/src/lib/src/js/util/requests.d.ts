import { IMobiscrollUtils } from '../core/mobiscroll';
declare module '../core/mobiscroll' {
    export interface IMobiscrollUtils {
        getJson(url: string, callback: (data: any) => void, type: string): void;
    }
}