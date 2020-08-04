import { IMobiscrollUtils } from '../core/mobiscroll';
declare module '../core/mobiscroll' {
    export interface IMobiscrollUtils {
        datetime: {
            parseDate: (format: string, value: string, settings?: any) => Date;
            formatDate: (format: string, value: Date, settings?: any) => string;
        }
    }
}