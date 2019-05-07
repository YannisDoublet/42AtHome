import React from 'react';
import './tags.css'

const Tags = (props) => {
    const renderTags = (tags) => {
        return tags.map((tag, i) => (
            <div key={i} className={'tag'}>
                {tag}
            </div>
        ));
    };

    return (
        <div id={'tags_container'}>
            {renderTags(props.tags)}
        </div>
    );
};

export default Tags;
