# bs-react-datepicker

Bucklescript/Reason bindings for react-datepicker

## Info
🚧 This is a WIP library. Most of the basic features are implemented, but some are still left not working. If you would like to help with the development effort, feel free to submit a pull request 🚧

This library provides Bucklescript/Reason bindings for [react-datepicker](https://github.com/Hacker0x01/react-datepicker).

## Dependencies
Apart from bucklescript itself, the only requirement for using bs-react-datepicker is [bs-moment](https://github.com/reasonml-community/bs-moment)

## Installation
In your terminal, run
```
npm i --save bs-react-datepicker
```

Include it in your `bsconfig.json`
```json
"bs-dependencies": [
  "reason-react",
  "bs-moment"
],
```


Then include it in your reason project
```ocaml
open ReactDatepicker;
```

## Example

The primary component is, of course `DatePicker`.
```ocaml
open ReactDatepicker;
open MomentRe;

type state = {
  currentDate: Moment.t
};

type action =
  | UpdateDate(Moment.t);

let component = ReasonReact.reducerComponent("TestDatepicker");


let make(children) {
  ...component,
  initialState: () => {
    currentDate: momentNow()
  },
  reducer: (action: action, state: state) => switch action {
    | UpdateDate(date) => ReasonReact.Update({...state, currentDate: date})
  },
  render: (self) => {
    <DatePicker
    dropdownMode = Select
    dateFormat = "YYYY-MM-DD"
    selected = self.state.currentDate
    onChange=((date) => self.send(UpdateDate(date)))>
    </DatePicker>
  }
}
```

## To Do
❌ Include more examples

❌ Implement more callbacks

❌ Implement `popper` props

## Maintainers
[Zach Baylin](http://github.com/zbaylin) (me@zachbayl.in)

[Ohad Rau](http://github.com/OhadRau) (admin@ohad.space)
