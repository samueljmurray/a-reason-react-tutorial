import React, { Component } from "react";

class Input extends Component {
  constructor() {
    super();
    this.state = {
      value: ""
    };
  }

  render() {
    return (
      <input
        value={this.state.value}
        type="text"
        onChange={evt => {
          this.setState({ value: evt.target.value });
        }}
        onKeyDown={evt => {
          if (evt.keyCode === 13) {
            this.props.onSubmit(this.state.value);
            this.setState({ value: "" });
          }
        }}
      />
    );
  }
}

export default Input;
