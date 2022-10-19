import Row from "./Row";
import ReactDOM from 'react-dom';
import ChessBoard from './ChessBoard';

function Table(info) {
//   let list;
// for (const i of info) {
//   list+=Row(i);
//   console.log("jopa");
//   ReactDOM.render(list,document.getElementById('root'))
// }
  return (
    <div className="App">
      <header className="App-header">
        <p> Date {new Date().toLocaleDateString()}.</p>
      </header>
      <div className="Table">

        <table>
          <tbody>
          {Row(info.length,[...info])}
          </tbody>
        </table>
        <hr></hr>
        <table className="chess">
          <tbody>
            {ChessBoard()}
          </tbody>
        </table>
      </div>
    </div>
  );
}

export default Table;
