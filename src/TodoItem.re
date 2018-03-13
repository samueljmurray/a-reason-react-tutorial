type item = {
  id: int,
  title: string,
  completed: bool
};

let component = ReasonReact.statelessComponent("TodoItem");
let make = (~item, ~onToggle, children) => {
  ...component,
  render: (_) => {
    <div className="items" onClick=((_evt) => onToggle())>
      <input
        _type="checkbox"
        checked=(Js.Boolean.to_js_boolean(item.completed))
      />
      (ReasonReact.stringToElement(item.title))
    </div>
  }
};
