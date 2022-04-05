import React from "react";

class Clock extends React.Component {
  render() {
    let options = { hour12: false };
    (this.props.format == 12) ? options.hour12 = true : options.hour12 = false;
    return <div >{this.state.date.toLocaleString("ru-RU", options)}</div>
  }


  componentDidMount() {
    this.timerID = setInterval(() => this.tick(), 1000)
  }

  tick() {
    this.setState({ date: new Date(new Date().toISOString().replace("Z", this.props.timezone)) });
  }
  constructor(props) {
    super(props);
    this.state = { date: new Date(new Date().toISOString().replace("Z", this.props.timezone)) }
  }
}
export default Clock;