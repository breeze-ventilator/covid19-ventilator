import React, { Component } from 'react';
import ReactDOM from 'react-dom';
import { IMobiscroll as _IMobiscroll } from '../core/mobiscroll';
import { MbscNumpadOptions, MbscNumpadDecimalOptions, MbscNumpadDateOptions, MbscNumpadTimeOptions, MbscNumpadTimespanOptions } from '../classes/numpad';
import { MbscSelectOptions } from '../presets/select';
/**
 * Generic base types for use later
 * --------------------------------
 */
/**
 * Base type for the Components
 * Enabes to define an interface property as "new"-able.
 */
interface MbscComponent<BaseOptionType, AdditionalPropTypes = {}> extends Component<BaseOptionType | AdditionalPropTypes> {
    new(): Component<BaseOptionType | AdditionalPropTypes>;
}
interface InputPassThroughProps {
    className?: string;
    placeholder?: string;
    type?: string;
}
interface InputBaseComponent<BaseOptionType, AdditionalPropTypes = {}> extends MbscComponent<BaseOptionType | InputPassThroughProps, AdditionalPropTypes> { }
/**
 * Base prop-type for a generic value
 */
type ValuePropType<V> = { value?: V };
/**
 * Prop type for components that accept date as value prop
 */
type MbscDateType = string | Date | object;
type DateValueProp = ValuePropType<MbscDateType>;
/**
 * Prop type for components that accept number as value prop
 */
type NumberValueType = ValuePropType<number>;
/**
 * Prop type for components that accept anything as value prop
 */
type AnyValueProp = ValuePropType<any>;
/**
 * Prop type for components that accept string as value prop
 */
type StringValueProp = ValuePropType<string>;
/**
 * Prop type for components that accept className as prop type
 */
interface ClassNameProp {
    className?: string;
}
type NumpadValueProp = ValuePropType<number | string | Date>;
type NumpadProps = NumpadValueProp | MbscNumpadOptions | MbscNumpadDecimalOptions | MbscNumpadDateOptions | MbscNumpadTimeOptions | MbscNumpadTimespanOptions;
/**
 * Interface definitions
 * ---------------------
 */
export interface NumpadComponent extends InputBaseComponent<NumpadProps> { }
export interface SelectComponent extends InputBaseComponent<MbscSelectOptions, StringValueProp> { }
/**
 * Const definitions
 * -----------------
 * Enable the following syntax: import { Calendar } from '@mobiscroll/react'
 */
export const Numpad: NumpadComponent;
export const Select: SelectComponent;
/**
 * Namespace definitions
 * ---------------------
 * Enable the use of components under the mobiscroll namespace:
 * Ex.: <mobiscroll.Calendar />
 */
export interface IMobiscroll extends _IMobiscroll {
    Numpad: NumpadComponent;
    Select: SelectComponent;
}
export const mobiscroll: IMobiscroll;
export as namespace mobiscroll;
export default mobiscroll;