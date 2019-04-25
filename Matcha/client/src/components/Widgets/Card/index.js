import React from 'react';
import './card.css'

const Card = () => {

    const renderCard = () => {
        console.log('salut');
    };

    return (
        <div className="grid_container">
            <div className="content">
                {renderCard()}
            </div>
        </div>
    );
};

export default Card;
