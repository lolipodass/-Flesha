import React from "react";

function CommentsList(props) {
    const comments = props.comments.map((elem, index) => {
        return (
            <div className="comment" id={"comment-" + index} key={"comment-" + index}>
                <div className="comment_name">{elem["userName"]}</div>
                <div className="comment_text">{elem["userText"]}</div>
                <div id="comment_delete" onClick={(event) => props.deleteFunction(event)}>Удалить</div>
                <div id="comment_edit" onClick={(event) => props.editFunction(event)}>Редактировать</div>
                <div id="comment_show" onClick={(event) => props.showFunction(event)}>Просмотреть</div>
            </div>
        );
    });

    return (
        <div className="comments">
            {comments}
        </div>
    );

}

export default CommentsList;