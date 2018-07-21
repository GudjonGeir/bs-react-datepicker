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
    dropdownMode = `Scroll
    selected = self.state.currentDate
    onChange=((date) => self.send(UpdateDate(date)))>
    </DatePicker>
  }
}