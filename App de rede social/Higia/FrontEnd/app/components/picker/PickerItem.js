import React from 'react';
import { TouchableHighlight, Text, StyleSheet } from 'react-native';

import colors from '../../config/colors';

export default function PickerItem({label, onPress}) {
    return (
        <TouchableHighlight style={styles.item} underlayColor={colors.light} onPress={onPress}>
            <Text numberOfLines={1}>{label}</Text>
        </TouchableHighlight>
    );
}

const styles = StyleSheet.create({
    item: {
        padding: "4%",
    },
})
