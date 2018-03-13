import React from "react";

export default ({ item, onToggle }) => (
  <div className="items" onClick={onToggle} >
    <input
      type="checkbox"
      checked={item.completed}
    />
    {item.title}
  </div>
);
