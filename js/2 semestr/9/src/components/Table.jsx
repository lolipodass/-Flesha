import { useState } from "react"
import "./../table.css"


function Table() {
    let [data, useData] = useState([
        {
            name: "Butter", price: 48.9, amount: 34,
            image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis antoher text om my goad i ndeed it",
            isNew: true, discount: 0.1, isHidden: false,
        },
        {
            name: "Fancy", price: 97, amount: 88,
            image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: false, discount: 0,isHidden: false,
        },
        {
            name: "Cream", price: 45.9, amount: 44, image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: false, discount: 0.01,isHidden: false,
        },
        {
            name: "Milk", price: 51.9, amount: 72, image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: true, discount: 0.03,isHidden: false,
        },
        {
            name: "Yoghurt", price: 67.4, amount: 85, image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: true, discount: 0.07,isHidden: false,
        },
        {
            name: "Test", price: 44, amount: 20,
            image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: false, discount: 0,isHidden: false,
        },
        {
            name: "Janie", price: 31.9, amount: 52, image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: false, discount: 0.01,isHidden: false,
        },
        {
            name: "Marvin", price: 58.9, amount: 19, image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: false, discount: 0.03,isHidden: false,
        },
        {
            name: "Beatrice", price: 22.4, amount: 70, image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: false, discount: 0.07,isHidden: false,
        },
        {
            name: "Bertha", price: 17.9, amount: 48, image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: false, discount: 0.01,isHidden: false,
        },
        {
            name: "Elizabeth", price: 11.9, amount: 92, image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: false, discount: 0.03,isHidden: false,
        },
        {
            name: "Ida", price: 95.4, amount: 78, image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: false, discount: 0.07,isHidden: false,
        },
        {
            name: "Harry", price: 34.9, amount: 5, image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: false, discount: 0.01,isHidden: false,
        },
        {
            name: "Ray", price: 41.9, amount: 83, image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: false, discount: 0.03,isHidden: false,
        },
        {
            name: "Walter", price: 60.4, amount: 63, image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: false, discount: 0.07,isHidden: false,
        },
        {
            name: "Sara", price: 49.9, amount: 98, image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: false, discount: 0.01,isHidden: false,
        },
        {
            name: "Andre", price: 16.9, amount: 97, image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: false, discount: 0.03,isHidden: false,
        },
        {
            name: "Rena", price: 69.4, amount: 58, image: "https://www.ikea.com/us/en/images/products/tjalla-wall-clock__0633571_pe695905_s5.jpg",
            description: "lorem impus guchi gang shit shiis",
            isNew: false, discount: 0.07,isHidden: false,
        },
    ]);

    let [values, useValues] = useState([1, -1]);
    let [environment, useEnvironment] = useState();


    let table = [];

    let sorting = (now, prev) => {
        if (now.isNew)
            return -1;
        if (now[environment] < prev[environment]) return values[0]
        if (now[environment] > prev[environment]) return values[1]
        return 0
    }
    console.log(data);

    for (let i = 0; i < data.length; i++) {
        if (data[i].isHidden)
            continue;
        table.push(
            <div key={i} className="element">
                <img src={data[i].image} />
                {data[i].isNew&&<div className="new">Новинка</div>}
                { data[i].discount>0&& <div className="discount">{Math.round(data[i].discount * 100)}%</div>}
                <div className="info">
                    <h2>{data[i].name}</h2>
                    <h3>Цена: {data[i].price}</h3>
                    <h3>Количество: {data[i].amount}</h3>
                    <p>{data[i].description}</p>
                </div>
            </div>
        )
    }

    return (
        <>
        <div className="row">
                {table}
        </div>
       
            <div className="row">

            <button onClick={Sorting} className="button" >Name</button>
            <button onClick={Sorting} className="button" >Price</button>
                <button onClick={Sorting} className="button" >Amount</button>
                <input type="text" className="search" onChange={Find} />
            </div>
        </>

    );

    function Find(e)
    {
        const val = e.target.value;
        const Func = function (elem) {
            if (elem.name.search(val) == -1)
                elem.isHidden = true;
            else
                elem.isHidden = false;
            return elem;
        }

        useData((data) => data.map(Func));   
    }


    function Change(environment) {
        useEnvironment(environment)
        useData((prev) => prev.sort(sorting));
        useValues((prev) => [prev[1], prev[0]]);
    }

    function Sorting(event) {
        // console.log(event.target)
        switch (event.target.innerHTML) {
            case 'Name':
                Change("name");
                break;
            case 'Price':
                Change("price");
                break;
            case 'Amount':
                Change("amount");
                break;
            case 'is New?':
                Change("isNew");
                break;
            case 'discount':
                Change("discount");
                break;
        }
    }
}
export default Table;