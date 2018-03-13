import React, { Component } from "react";
import Input from "./Input";
import TodoItem from "./TodoItem";

class TodoApp extends Component {
  constructor() {
    super();
    this.lastId = 0;
    this.state = {
      items: [
        {
          id: this.lastId,
          title: "Write some things to do",
          completed: false
        }
      ]
    };
    this.newItem = this.newItem.bind(this);
  }

  newItem(text) {
    this.lastId = this.lastId + 1;
    return {
      id: this.lastId,
      title: text,
      completed: false
    }
  }

  render() {
    const numItems = this.state.items.length;
    const numCompleted = this.state.items.filter(item => item.completed).length;
    return (
      <div className="app">
        <div className="title">
          What to do
          <Input onSubmit={(text) => {
            this.setState((state) => ({
              ...state,
              items: [
                this.newItem(text),
                ...state.items
              ]
            }))
          }} />
        </div>
        <div className="items">
          {
            this.state.items.map(item => (
              <TodoItem
                key={item.id}
                item={item}
                onToggle={() => {
                  this.setState(state => {
                    const itemsToUpdate = state.items;
                    const itemIndex = itemsToUpdate.findIndex(i => item.id === i.id);
                    itemsToUpdate[itemIndex].completed = !itemsToUpdate[itemIndex].completed;
                    return {
                      ...state,
                      items: itemsToUpdate
                    };
                  })
                }}
              />
            ))
          }
        </div>
        <div className="footer">
          {numItems} {numItems !== 1 ? " items" : " item"} ({numCompleted} completed)
        </div>
      </div>
    );
  }
}

export default TodoApp;
