type state = {
  items: list(TodoItem.item)
};
type action =
  | AddItem(string)
  | ToggleItem(int);

let component = ReasonReact.reducerComponent("TodoApp");
let lastId = ref(0);
let newItem = (text): TodoItem.item => {
  lastId := lastId^ + 1;
  {
    id: lastId^,
    title: text,
    completed: false
  }
};

let make = (_) => {
  ...component,
  initialState: () => {
    items: [
      {
        id: 0,
        title: "Write some things to do",
        completed: false
      }
    ]
  },
  reducer: ((action), {items}) =>
    switch action {
    | AddItem(text) => ReasonReact.Update({items: [newItem(text), ...items]})
    | ToggleItem(id) =>
      let items = List.map(
        (item: TodoItem.item) =>
          item.id === id
            ? {
              ...item,
              completed: !item.completed
            }
            : item,
          items
      );
      ReasonReact.Update({items: items})
    },
  render: ({state: {items}, reduce}) => {
    let numItems = List.length(items);
    let numCompleted =
      List.filter(((item: TodoItem.item) => item.completed), items)
      |> List.length;

    <div className="app">
      <div className="title">
        (ReasonReact.stringToElement("What to do"))
        <Input onSubmit=(reduce((text) => AddItem(text))) />
      </div>
      <div className="items">
        (
          List.map((item: TodoItem.item) => <TodoItem
            key=(string_of_int(item.id))
            onToggle=(reduce(() => ToggleItem(item.id)))
            item
          />, items)
          |> Array.of_list
          |> ReasonReact.arrayToElement
        )
      </div>
      <div className="footer">
        (
          ReasonReact.stringToElement(
            string_of_int(numItems) ++ (numItems !== 1 ? " items" : " item") ++ " (" ++ string_of_int(numCompleted) ++ " completed)"
          )
        )
      </div>
    </div>
  }
};
