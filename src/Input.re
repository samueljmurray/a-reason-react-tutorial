type state = string;

let valueFromEvent = (evt) : string => (
  evt
  |> ReactEventRe.Form.target
  |> ReactDOMRe.domElementToObj
)##value;
let component = ReasonReact.reducerComponent("Input");

let make = (~onSubmit, _) => {
  ...component,
  initialState: () => "",
  reducer: (newText, _currentText) => ReasonReact.Update(newText),
  render: ({state: text, reduce}) =>
    <input
      value=text
      _type="text"
      onChange=(reduce((evt) => valueFromEvent(evt)))
      onKeyDown=((evt) =>
        if (ReactEventRe.Keyboard.key(evt) == "Enter") {
          onSubmit(text);
          (reduce(() => ""))()
        }
      )
    />
}