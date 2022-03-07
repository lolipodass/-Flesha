import React from "react";

import ReactDOM from "react-dom";

function Row(len,props){
    let data = [];
    
    for (let i=0;i<len;i++) {
        data.push(
            <tr key={i}>
                <td>{props[i].stock_name}</td>
                <td>{props[i].company_name}</td>
                <td>{props[i].price}</td>
                <td>{props[i].currency}</td>
                {(+props[i].change > 0) ? <td className="rise">{props[i].change}</td> : <td className="fall">{props[i].change}</td>}
            </tr>
        );
    }
    console.log(data[0].props);
    return data;
}

export default Row;