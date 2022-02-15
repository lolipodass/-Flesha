import React from "react";

import ReactDOM from "react-dom";

function Row(props){
    let jopa=<div></div>;
    for (let i=0;i<1;i++) {
        jopa+=(
            <tr>
            <td>{props[i].stock_name}</td>
            <td>{props[i].company_name}</td>
            <td>{props[i].price}</td>
            <td>{props[i].currency}</td>
            <td>{props[i].change}</td>
        </tr>)
    }
    console.log(jopa);
    return (
        <tr>
            <td>{props.stock_name}</td>
            <td>{props.company_name}</td>
            <td>{props.price}</td>
            <td>{props.currency}</td>
            <td>{props.change}</td>
        </tr>
    )
}

export default Row;